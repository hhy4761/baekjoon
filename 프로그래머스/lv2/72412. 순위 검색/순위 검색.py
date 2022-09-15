from itertools import combinations
from collections import defaultdict

def solution(info, query):
    answer = []
    info_dict = defaultdict(list)
    
    # 가능한 모든 케이스를 나눠서 딕셔너리에 저장
    for line in info:
        line = line.split()
        keys = line[:-1]
        value = int(line[-1])
        for i in range(5):
            for c in combinations(keys, i):
                new_key = ''.join(c)
                info_dict[new_key].append(value)
                
    # 이분탐색을 위해 오름차순 정렬
    for k in info_dict.keys():
        info_dict[k].sort()
    
    # query를 info_dict 형식에 맞게 파싱
    for q in query:
        q = q.replace("and","")
        q = q.replace("-","")
        q = q.split()
        line = q[:-1]
        min_val = int(q[-1])
        new_query = ''.join(line)
        
        if len(info_dict[new_query]) > 0:
            left = 0
            right = len(info_dict[new_query])-1
            
            # 이분탐색 할 필요 없는 케이스
            if info_dict[new_query][left] >= min_val:
                answer.append(len(info_dict[new_query]))
                continue
            elif info_dict[new_query][right] < min_val:
                answer.append(0)
                continue
            
            # 기준 점수보다 높은 인원 수 이분 탐색
            while left+1 < right:
                mid = (left+right)//2

                # F~T 
                if info_dict[new_query][mid] >= min_val:
                    right = mid
                else:
                    left = mid

            # F중에서 가장 작은 인덱스부터 끝
            answer.append(len(info_dict[new_query]) - right)
            
        else:
            answer.append(0)
    
    return answer