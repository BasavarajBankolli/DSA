### Python
```python
def quick(arr,low,high):
    if low < high:

        splitpoint = partition(arr,low,high)
        quick(arr,low,splitpoint-1)
        quick(arr,splitpoint+1,high)
          

def partition(arr,low,high):
 
          left = low+1
          right = high
          piviotvalue = arr[low]

          do = False
          while not do:
              while left <= right and arr[left] <= piviotvalue:
                            left =+ 1

              while right >= left and arr[right] >= piviotvalue:
                            right -= 1
    
              if right < left:
    
                    do = True
              else:

                   temp = arr[left]
                   arr[left] = arr[right]
                   arr[right] = temp

          
          arr[low] = arr[right]
          arr[right] = piviotvalue
          return right
      
arr = [2,3,6,1,5]
quick(arr,0,len(arr)-1)
print(arr)
```

## Output
```
[1,2,3,5,6]
```
