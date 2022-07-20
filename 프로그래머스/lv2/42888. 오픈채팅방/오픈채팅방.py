from collections import defaultdict
def solution(record):
    ans = []
    user = defaultdict(str)
    for r in record:
        if r.split()[0] in ['Enter','Change']:
            user[r.split()[1]] = r.split()[2]
            
    for r in record:
        if r.split()[0] == 'Enter':
            name = user[r.split()[1]]
            ans.append(name+"님이 들어왔습니다.")
        elif r.split()[0] == 'Leave':
            name = user[r.split()[1]]
            ans.append(name+"님이 나갔습니다.")
    return ans