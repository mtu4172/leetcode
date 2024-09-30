# Link : https://leetcode.com/problems/number-of-atoms/

class Solution(object):
    def countOfAtoms(self, formula):
        """
        :type formula: str
        :rtype: str
        """
        atoms = {}
        stack = [1]
        idx = len(formula)-1
        jdx = len(formula)-1
        number = 1
        ele = ""
        while idx >= 0:
            if formula[idx].isnumeric():
                jdx = idx
                while formula[jdx].isnumeric():
                    jdx -= 1
                number = int(str(formula[jdx+1:idx+1]))
                idx = jdx
            if formula[idx] == ')':
                stack.append(stack[-1] * number)
                number = 1
                idx -= 1
            if formula[idx] == '(':
                stack.pop()
                idx -= 1
            if formula[idx].isalpha():
                jdx = idx
                while formula[jdx].islower():
                    jdx -= 1
                ele = str(formula[jdx:idx+1])
                idx = jdx-1
                if ele not in atoms:
                    atoms[ele] = 0
                atoms[ele] += number * stack[-1]
                number = 1
        elems = sorted(atoms.keys())
        result = ""
        for i in elems:
            count = atoms[i]
            result += i
            if count > 1:
                result += str(count)
        return result
        