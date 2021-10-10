class Solution:
    '''
        For n length vowel permutations:-
        1. Loop through the vowels
        2. Fill the first index with the current vowel
        3. For the next index, fill the values from the followedBy list of chosen vowel
        4. Repeat/Recur Step 3 till n > 1
        5. Repeat Step 1 for the remaining vowels
    '''
    def dpFn(self, followedBy, vowel, n, lookup):
        key = (vowel, n)
        if key not in lookup:
            if n > 1:
                count = 0
                for vowel in followedBy[vowel]:
                    count += self.dpFn(followedBy, vowel, n - 1, lookup)
                lookup[key] = count
            elif n == 1:
                lookup[key] = len(followedBy[vowel])
            else:
                lookup[key] = 0
        return lookup[key] % ((10 ** 9) + 7)

    def countVowelPermutation(self, n: int) -> int:
        vowels = ["a", "e", "i", "o", "u"]
        if n == 1:
            return len(vowels)
        followedBy = {"a": ["e"], "e": ["a", "i"], "i": ["a", "e", "o", "u"], "o": ["u", "i"], "u": ["a"]}
        count = 0
        lookup = {}
        for vowel in vowels:
            count += self.dpFn(followedBy, vowel, n - 1, lookup)
        return count % ((10 ** 9) + 7)
