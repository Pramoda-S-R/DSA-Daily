class Solution(object):
    def isValidSudoku(self, board):
        seen = set()
        for i in range(9):
            for j in range(9):
                val = board[i][j]
                
                if val != ".":
                    # Replaced f-strings with universal string formatting
                    row_key = "{} in row {}".format(val, i)
                    col_key = "{} in col {}".format(val, j)
                    box_key = "{} in box {}-{}".format(val, i // 3, j // 3)
                    
                    if row_key in seen or col_key in seen or box_key in seen:
                        return False
                    
                    seen.add(row_key)
                    seen.add(col_key)
                    seen.add(box_key)
                    
        return True
