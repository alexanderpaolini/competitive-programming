

def solve():
    S = input()
    P = input()

    n = len(S)
    m = len(P)

    #equal
    if S == P:
        print("Yes")
        return 
    
    #check preprending and apppending digit
    if P in S and (S[0].isdigit() or S[-1].isdigit()) and n - m == 1:
        print("Yes")
        return 
    
    resulting_string = ""
    for c in P:
        if c.isalpha():
            if c.isupper():
                resulting_string += c.lower()
            else:
                resulting_string += c.upper()
        else:
            resulting_string += c
    
    return print("Yes") if resulting_string == S else print("No")
    


solve()