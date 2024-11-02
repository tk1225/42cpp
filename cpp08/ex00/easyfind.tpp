template <typename T>
void EasyFind(T& val, int find) {
  typename T::iterator it = std::find(val.begin(), val.end(), find);

  if (it != val.end()) {
    std::cout << "Value " << find << " found at position "
              << std::distance(val.begin(), it) << std::endl;
  } else {
    std::cout << "Value " << find << " not found" << std::endl;
  }
}
