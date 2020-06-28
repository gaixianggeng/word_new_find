# 字典排序
# 基于快排的实现

origin_str = "abcba"
sort_list = ["abcba","bcba","cba","ba","a"]
end = len(origin_str)-1
start = 0

def quick_sort(sort_list,start,end):
    print(sort_list)
    while(start < end):
        i = partition(sort_list,start,end)
        quick_sort(sort_list,start,i-1)
        start=i+1
    print(sort_list)
    return

def partition(sort_list,start,end):
    tmp = sort_list[start]
    while(start< end):
        while(start<end and sort_list[end]>tmp):
            end-=1
        if start<end:
            sort_list[start] = sort_list[end]
        while(start<end and sort_list[start]<=tmp):
            start+=1
        if start < end:
            sort_list[end] = sort_list[start]
            end-=1
    sort_list[start] = tmp
    return start


quick_sort(sort_list,start,end)
