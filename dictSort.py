# 字典排序
# 基于快排的实现

origin_str = "abcba"
sort_list = []
end = len(origin_str)
start = 0

def quick_sort(origin_str,sort_list,start,end):
    while(start < end):
        i = partition(sort_list,origin_str,start,end)
        quick_sort(sort_list,origin_str,start,end-1)
        start+=1
    return

def partition(sort_list,origin_str,start,end):
    _tmp = sort_list[start]
    tmp = str(sort_list[start])
    while(left < end):
        while(start<end and sort_list[end]>tmp):
            end-=1
        if start<end:
            sort_list[start] = sort_list[end]
        while(start<end and sort_list[start]<=tmp):
            start+=1
        if start < end:
            sort_list[end] = sort_list[start]
            end-=1
    sort_list[start] = _tmp
    return start


quick_sort(origin_str,sort_list,start,end)
