from collections import defaultdict
def solution(phone_book):
    pb = defaultdict(bool)
    phone_book.sort()
    for p in phone_book:
        
        for i in range(len(p)):
            if pb[p[:i+1]]:
                return False
        pb[p] = True

    return True