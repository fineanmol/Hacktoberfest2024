def length_of_longest_substring(s: str) -> int:
    """
    Find the length of the longest substring without repeating characters.

    Args:
        s (str): The input string.

    Returns:
        int: The length of the longest substring without repeating characters.

    Examples:
        >>> length_of_longest_substring("abcabcbb")
        3
        >>> length_of_longest_substring("bbbbb")
        1
        >>> length_of_longest_substring("pwwkew")
        3
        >>> length_of_longest_substring("")
        0
    """
    char_set = set()
    max_len = 0
    start = 0

    for end in range(len(s)):
        while s[end] in char_set:
            char_set.remove(s[start])
            start += 1
        char_set.add(s[end])
        max_len = max(max_len, end - start + 1)

    return max_len

if __name__ == "__main__":
    import doctest

    doctest.testmod()
