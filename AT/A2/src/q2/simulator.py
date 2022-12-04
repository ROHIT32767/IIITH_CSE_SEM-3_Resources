from rule import *
'''
x=no of iterations
row=total number of rows
column=total number of columns
row1=current row
column1=current column
curr_itr=current number of iteration
r1=previous row
c1=previous column
r2=next row
c2=next column
'''
row=0
column=0
k=0
row1=0
column1=0
r1=0
c1=0
r2=0
c2=0
r3=0
c3=0
with open('./q2/config.txt') as f:
    for line in f:
        line1=line.split()
        row=int(line1[1])
        column=int(line1[0])
        k=int(line1[2])
        break
startarr=[[0 for i in range(column)] for j in range(row)]
f.close()
with open('./q2/config.txt') as f:
        flag=0
        for line in f:
            if(flag==1):
                line1=line.split()
                row1=row-int(line1[1])
                column1=int(line1[0])-1
                startarr[row1][column1]=1
            else:
                flag=1
for i in range(row):
        for j in range(column):
            print(startarr[i][j],end="")
        print()

f.close()
while(1):
    x=input("Input the number of Iterations:")
    arr = [[0 for i in range(column)] for j in range(row)]
    copyarr=[[0 for i in range(column)] for j in range(row)]
    for i in range(row):
        for j in range(column):
            arr[i][j]=startarr[i][j] 
    if(int(x)==-1):
        break
    if(int(x)!=0):
        curr_itr=0
        while(curr_itr<int(x)):
            for i in range(row):
                for j in range(column):
                    r1=i-1
                    c1=j-1
                    r2=i+1
                    c2=j+1
                   # print(str(r1)+" "+str(r2)+" "+str(c1)+" "+str(c2))
                    L=[]
                    for r3 in range(r1,r2+1,1):
                        for c3 in range(c1,c2+1,1):
                            if(r3<0 or r3>(row-1)):
                                L.append(int(0))
                            elif(c3<0 or c3>(column-1)):
                                L.append(int(0))
                            elif(r3!=i or c3!=j):
                                L.append(int(arr[r3][c3]))
                   # print(L)
                   # print(int(arr[i][j]))
                    copyarr[i][j]=rule(int(arr[i][j]),L)
            for i in range(row):
                for j in range(column):
                    arr[i][j]=copyarr[i][j]          
            curr_itr=curr_itr+1
    file1 = open('./q2/output.txt','w')
    for i in range(row):
        s=""
        for j in range(column):
            if(arr[i][j]==1):
                s+='X'
            elif(arr[i][j]==0):
                s+='O'
        s+='\n'
        file1.writelines(s)
    file1.close()     
    for i in range(row):
        for j in range(column):
            print(arr[i][j],end="")
        print()



