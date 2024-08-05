template <typename T>
void EasyFind<T>::seekInt() {
  typename T::iterator it = std::find(value.begin(), value.end(), find);

  if (it != value.end()) {
    std::cout << "Value " << find << " found at position "
              << std::distance(value.begin(), it) << std::endl;
  } else {
    std::cout << "Value " << find << " not found" << std::endl;
  }
}
