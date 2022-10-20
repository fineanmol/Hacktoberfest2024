class Solution:
  def isScramble(self, s1: str, s2: str) -> bool:
    if s1 == s2:
      return True
    if len(s1) != len(s2):
      return False
    if Counter(s1) != Counter(s2):
      return False

    for i in range(1, len(s1)):
      if self.isScramble(s1[:i], s2[:i]) and self.isScramble(s1[i:], s2[i:]):
        return True
      if self.isScramble(s1[:i], s2[len(s2) - i:]) and self.isScramble(s1[i:], s2[:len(s2) - i]):
        return True

    return False
