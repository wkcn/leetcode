class Solution:
    def destCity(self, paths: List[List[str]]) -> str:
        ase = set(e[0] for e in paths)
        bse = set(e[1] for e in paths)
        return list((ase | bse) - ase)[0]
