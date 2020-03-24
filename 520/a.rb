n = gets.to_i
arr = gets.chomp.split(" ").map(&:to_i)

if n==1000
  puts 999
  exit
end

if n==1
  puts 0
  exit
end

#arr.push 1000
count = 0
currange = arr[0]
inrange = true
switch = true

(1..n-1).each do |i|
  if arr[i]==(arr[i-1]+1)
    count += 1
    switch = true
    inrange = true
  else
    if switch
      count -=1 unless ((currange == 1))
    end
    inrange = false
    switch = false
    currange = arr[i]
  end
end

#puts count
if currange==1 or not switch
else
  count -= 1 if switch
end

if arr[n-1]==1000 and arr[n-2]==999
  count += 1
end


puts [count,0].max
