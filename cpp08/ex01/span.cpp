#include "span.hpp"

Span::Span() {}

Span::Span(unsigned int store_len) : len(store_len) {}

Span::~Span() {}

Span::Span(const Span& SpanClass) { *this = SpanClass; }

Span& Span::operator=(const Span& SpanClass) {
  if (this != &SpanClass) {
    this->len = SpanClass.len;
  }
  return *this;
}

void Span::addNumber(int n) {
  if (this->store.size() >= len) {
    throw std::runtime_error("store capacity is full");
  } else {
    this->store.push_back(n);
  }
}

unsigned int Span::shortestSpan() {
  if (store.size() <= 1) {
    throw std::runtime_error("store capacity is not enough");
  }

  unsigned int diff = std::numeric_limits<unsigned int>::max();
  for (std::size_t i = 0; i < store.size(); ++i) {
    unsigned int tmp_diff = std::abs(store[i] - store[i + 1]);
    if (tmp_diff < diff) {
      diff = tmp_diff;
    }
  }
  return diff;
}

unsigned int Span::longestSpan() {
  if (store.size() <= 1) {
    throw std::runtime_error("store capacity is not enough");
  }

  unsigned int diff = 0;
  for (std::size_t i = 0; i < store.size(); ++i) {
    unsigned int tmp_diff = std::abs(store[i] - store[i + 1]);
    if (tmp_diff > diff) {
      diff = tmp_diff;
    }
  }
  return diff;
}
