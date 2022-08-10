def solution(s):
    answer = []
    s = s[1:-1]
    res = []
    left,right = 0,0
    while right <= len(s)-1:
        while right <= len(s)-1 and s[right] != '}':
            right+=1
        arr = list(map(int,s[left+1:right].split(',')))
        res.append(arr)
        if s[right] == '}':
            right +=1
        if right <= len(s)-1 and s[right] == ',':
            right +=1
        left = right
    res.sort(key=lambda x: len(x))
    for r in res:
        for ele in r:
            if ele not in answer:
                answer.append(ele)
    return answer