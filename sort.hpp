#include <cmath>
#include <iterator>
#include <type_traits>
#include <utility>

namespace shirose {

template <typename Iterator>
struct is_random_access_iterator
    : std::is_same<typename std::iterator_traits<Iterator>::iterator_category,
                   std::random_access_iterator_tag> {};

template <typename RandomIt,
          typename std::enable_if_t<is_random_access_iterator<RandomIt>::value,
                                    std::nullptr_t> = nullptr>
void bubble_sort(RandomIt first, RandomIt last) {
  for (auto right = last; first < right; --right) {
    auto it1 = first;
    auto it2 = first + 1;
    while (it2 < right) {
      if (*it1 > *it2) std::swap(*it1, *it2);
      ++it1;
      ++it2;
    }
  }
}

template <typename RandomIt,
          typename std::enable_if_t<is_random_access_iterator<RandomIt>::value,
                                    std::nullptr_t> = nullptr>
void selection_sort(RandomIt first, RandomIt last) {
  auto find_min = [](RandomIt first, RandomIt last) {
    auto min = first++;
    for (auto it = first; it < last; ++it)
      if (*min > *it) min = it;
    return min;
  };

  for (auto it = first; it < last; ++it) {
    auto min = find_min(it, last);
    std::swap(*it, *min);
  }
}

template <typename RandomIt,
          typename std::enable_if_t<is_random_access_iterator<RandomIt>::value,
                                    std::nullptr_t> = nullptr>
void shaker_sort(RandomIt first, RandomIt last) {
  auto forward_scan = [](auto left, auto right) {
    auto it1 = left;
    auto it2 = it1 + 1;
    auto new_right = left;
    while (it2 < right) {
      if (*it1 > *it2) {
        std::swap(*it1, *it2);
        new_right = it2;
      }
      ++it1;
      ++it2;
    }
    return new_right;
  };

  auto reverse_scan = [](auto left, auto right) {
    auto it2 = right - 1;
    auto it1 = it2 - 1;
    auto new_left = right;
    while (it1 >= left) {
      if (*it1 > *it2) {
        std::swap(*it1, *it2);
        new_left = it1;
      }
      --it1;
      --it2;
    }
    return new_left;
  };

  auto left = first;
  auto right = last;
  while (true) {
    right = forward_scan(left, right);
    if (left == right) break;
    left = reverse_scan(left, right);
    if (left == right) break;
  }
}

template <typename RandomIt,
          typename std::enable_if_t<is_random_access_iterator<RandomIt>::value,
                                    std::nullptr_t> = nullptr>
void insertion_sort(RandomIt first, RandomIt last) {
  auto insert = [](RandomIt first, RandomIt last) {
    auto it1 = last - 1;
    auto it2 = last;
    const auto tmp = *last;
    while (it1 >= first && *it1 > tmp) {
      *it2 = *it1;
      --it1;
      --it2;
    }
    *it2 = tmp;
  };

  auto it1 = first;
  auto it2 = it1 + 1;
  while (it2 < last) {
    if (*it1 > *it2) insert(first, it2);
    ++it1;
    ++it2;
  }
}

template <typename RandomIt,
          typename std::enable_if_t<is_random_access_iterator<RandomIt>::value,
                                    std::nullptr_t> = nullptr>
void comb_sort(RandomIt first, RandomIt last) {
  auto h = (std::distance(first, last) * 10) / 13;
  bool is_swapped = false;

  while (h > 1 || is_swapped) {
    auto it1 = first;
    auto it2 = it1 + h;
    is_swapped = false;
    while (it2 < last) {
      if (*it1 > *it2) {
        std::swap(*it1, *it2);
        is_swapped = true;
      }
      ++it1;
      ++it2;
    }
    h = (h * 10) / 13;
  }
}

template <typename RandomIt,
          typename std::enable_if_t<is_random_access_iterator<RandomIt>::value,
                                    std::nullptr_t> = nullptr>
void norm_sort(RandomIt first, RandomIt last) {
  auto it1 = first;
  auto it2 = it1 + 1;
  while (it2 < last) {
    if (*it1 <= *it2) {
      ++it1;
      ++it2;
    } else {
      std::swap(*it1, *it2);
      --it1;
      --it2;
      if (it1 < first) {
        ++it1;
        ++it2;
      }
    }
  }
}

template <typename RandomIt,
          typename std::enable_if_t<is_random_access_iterator<RandomIt>::value,
                                    std::nullptr_t> = nullptr>
void shell_sort(RandomIt first, RandomIt last) {
  auto initial_gap = [](std::size_t n) {
    std::size_t h = 1;
    while (true) {
      const auto tmp = 3 * h + 1;
      if (tmp < n)
        h = tmp;
      else
        return h;
    }
  };

  const auto n = std::distance(first, last);
  auto h = initial_gap(n);
  while (h > 0) {
    auto left = first + h;
    while (left < last) {
      auto it1 = left - h;
      auto it2 = left;
      while (it1 >= first) {
        if (*it1 > *it2) std::swap(*it1, *it2);
        it1 -= h;
        it2 -= h;
      }
      ++left;
    }
    h = (h - 1) / 3;
  }
}

}  // namespace shirose