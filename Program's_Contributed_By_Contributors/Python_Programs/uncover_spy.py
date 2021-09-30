'''
In a city-state of n people, there is a rumor going around that one of the n people is a spy for the neighboring city-state.
The spy, if it exists:
Does not trust anyone else.
Is trusted by everyone else (he's good at his job).
Works alone; there are no other spies in the city-state.
You are given a list of pairs, trust. Each trust[i] = [a, b] represents the fact that person a trusts person b.
If the spy exists and can be found, return their identifier. Otherwise, return -1.
Example 1:
Input: n = 2, trust = [[1, 2]]
Output: 2
Explanation: Person 1 trusts Person 2, but Person 2 does not trust Person 1, so Person 2 is the spy.
Example 2:
Input: n = 3, trust = [[1, 3], [2, 3]]
Output: 3
Explanation: Person 1 trusts Person 3, and Person 2 trusts Person 3, but Person 3 does not trust either Person 1 or Person 2. Thus, Person 3 is the spy.
Example 3:
Input: n = 3, trust = [[1, 3], [2, 3], [3, 1]]
Output: -1
Explanation: Person 1 trusts Person 3, Person 2 trusts Person 3, and Person 3 trusts Person 1. Since everyone trusts at least one other person, there is no spy.
Example 4:
Input: n = 3, trust = [[1, 2], [2, 3]]
Output: -1
Explanation: Person 1 trusts Person 2, and Person 2 trusts Person 3. However, in this situation, we don't have any one person who is trusted by everyone else. So we can't determine who the spy is in this case.
Example 5:
Input: n = 4, trust = [[1, 3],[1, 4],[2, 3],[2, 4],[4, 3]]
Output: 3
Explanation: Person 1 trusts Person 3 and Person 4, Person 2 trusts Person 3 and Person 4, Person 4 trusts Person 3. Everyone trusts Person 3 but Person 3 does not trust anyone, so they are the spy.
[execution time limit] 4 seconds (py3)
[input] integer n
The number of people in the city-state
[input] array.array.integer trust
Array of pairs indicating who each person in trusts.
[output] integer
The identifier of the spy.
'''


def uncover_spy(n, trust):

    # check if n is trusted by everyone
    # create a dict with key of trust[i][1], value of += 1
    # if any of key == n -1, that means this person is truted by everyone
    # check if n does not trust anyone
    # if trust[i][0] dosen't have the above person then spy found
    trusted_index = {}
    not_trust = set()
    spy = -1
    for i in range(len(trust)):
        not_trust.add(trust[i][0])
        if trust[i][1] in trusted_index:
            trusted_index[trust[i][1]] += 1
        else:
            trusted_index[trust[i][1]] = 1
    print(trusted_index)
    print(not_trust)
    for key, value in trusted_index.items():
        if value == n-1:
            spy = key
    for val in not_trust:
        if spy not in not_trust:
            return spy
    return -1


'''
Time complexity: O(n+n+n) ~ O(n)
Space complexity: O(n+n+1) ~ O(n)
'''

n1 = 3
trust1 = [[1, 3], [2, 3], [3, 1]]

n2 = 4
trust2 = [[1, 3], [1, 4], [2, 3], [2, 4], [4, 3]]

print(uncover_spy(n1, trust1))
print(uncover_spy(n2, trust2))