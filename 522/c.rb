n = gets.to_i
a = gets.chomp.split(" ").map(&:to_i)

def getreq(x,arr,i,prev)
  if (!(arr[i+3].nil?) and x==4 and arr[i+2]==1.0 and arr[i+3]==-4) or (!(arr[i+3].nil?) and x==-4 and arr[i+2]==1.0 and arr[i+3]==4)
    puts -1
    exit
  end

  if x>0
    if (!(arr[i+3].nil?) and x<4 and arr[i+2]==1.0 and arr[i+3]<0)
      return 4-x
    end

    return 5-x
  else
    if (!(arr[i+3].nil?) and x>-4 and arr[i+2]==1.0 and arr[i+3]>0)
      return 2-x
    end

    return 1-x
  end
end

newa = [0]
a.each_with_index do |x,i|
  next if i==0
  if(x==a[i-1])
    newa.push 0
  elsif(x>a[i-1])
    newa.push 1
  else
    newa.push -1
  end
end

arr = []

#p newa
increasing = false
decreasing = false
count = 0

newa.each_with_index do |x,i|
  if x==0
    if increasing
      arr.push count
    end
    if decreasing
      arr.push 0-count
    end
    arr.push 0
    count = 0
    increasing = false
    decreasing = false
  elsif x==1
    if decreasing
      arr.push 0-count
      count = 0
    end
    increasing = true
    decreasing = false
    count = count+1
  else
    if increasing
      arr.push count
      count = 0
    end
    increasing = false
    decreasing = true
    count = count+1
  end
end

if increasing
  arr.push count
elsif decreasing
  arr.push (0-count)
end
#p arr

newarr = []
incount = false
count = 0.0
arr.each do |x|
  if x==0.0
    incount = true
    count += 1.0
  else
    if incount
      newarr.push count
      count = 0.0
      incount = false
    end
    newarr.push x
  end
end
if incount
  newarr.push count
end


p newarr

#=begin
len = arr.length
flag = 1
curr = 0
prev = 0

ansarr = []

newarr.each_with_index do |x,i|
  if x.class == Float
    nextone = newarr[i+1]
    if nextone.nil?
      ansarr.push 3
#      puts
#      exit
       break
    end
    nextreq = getreq(nextone,newarr,i,prev)

    if (nextreq+1)%5+1 == prev
      flag = 0
    end
    if (nextreq+2)%5+1 == prev
      flag = 1
    end
    

    (x-1).to_i.times do
      if flag==1
        curr = (nextreq+1)%5+1
        ansarr.push curr
        flag = 0
      else
        curr = (nextreq+2)%5+1
        ansarr.push curr
        flag = 1
      end
    end

#    if x==1 and nextreq==prev
#      puts -1
#      exit
#    end


    if (x==1) and prev == nextreq
      if nextone>0
        nextreq -= 1
      else
        nextreq += 1
      end
    end

    curr = nextreq
    ansarr.push curr
    prev = curr
  else
    if x>0
      x-1.times do
        curr = prev+1
        ansarr.push curr
        prev = curr
      end
      curr = 5
      ansarr.push curr
      prev = curr
    else
      (0-x-1).times do
        curr = prev-1
        ansarr.push curr
        prev = curr
      end
      curr = 1
      ansarr.push curr
      prev = curr
    end
  end
end

p ansarr

ansarr.each_with_index do |x,i|
  if x<1 or x>5
    puts -1
    exit
  end

  if x == ansarr[i+1]
    puts -1
    exit
  end
end

ansarr.each do |x|
  print "#{x} "
end
puts
