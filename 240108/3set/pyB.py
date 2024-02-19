# problem B




def sortDates(dates):
    month={"Jan":1, "Feb":2, "Mar":3, "Apr":4, "May":5, "Jun":6, "Jul":7, "Aug":8, "Sep":9, "Oct":10, "Nov":11, "Dec":12}
    n=len(dates)
    sort_arr=[]
    for i in range(n):
        temp = dates[i].split(' ')
        val=int(temp[2])*10000+month[temp[1]]*100+int(temp[0])
        sort_arr.append((val,dates[i]))

    sort_arr.sort()
    res=[]
    for i in range(n):
        res.append(sort_arr[i][1])
    return res


# n = int(input())
# data=[]
# for i in range(n):
#     s=input()
#     data.append(s)

# print(sortDates(data))