nm = gets.chomp.split(" ").map(&:to_i)
n = nm[0]
m = nm[1]


def nicep arr
  arr.each do |x|
    p x
  end
end

arr = []

m.times do
  arr.push []
end

n.times do
  sr = gets.chomp.split(" ").map(&:to_i)
  p sr
  s = sr[0]
  r = sr[1]

#  left = 0
#  right = arr[s-1].length-1
 
#  mid = (left+right)/2
#  prevmid = -1

=begin
  while left<right
    mid = (left+right)/2
    if arr[s-1][mid]<r
      right = mid
    else
      left = mid
    end
    break if prevmid==mid
    prevmid = mid
  end
=end

=begin
  i = 0
  arr[s-1].each do |x|
    if x<r
      break
    end
    i+=1
  end
=end

  arr[s-1].push(r)
#  nicep arr
end

(0..arr.length-1).each do |x|
  arr[x] = arr[x].sort.reverse
end

#nicep arr

newarr = []
(2*m).times do
  newarr.push []
end

arr.each_with_index do |subj,si|
  sum = 0
  subj.each do |asd|
    sum+=asd
    newarr[si].push sum
  end
end

#nicep arr
#nicep newarr

lengtharr = []
arr.each do |x|
  lengtharr.push x.length
end

iter = 0
ans = 0
prevpossans = 0
possans = 0
studpersubj = 0

#$lookup = Hash.new(nil)

def compute(arr,studpersubj,lengtharr)

#  ans = $lookup[studpersubj]
#  if not ans.nil?
#    return ans
#  end

  if studpersubj<0
    return -1
#  elsif studpersubj==0
    return 0
  end

  possans = 0
  arr.each_with_index do |subj,i|
    if (studpersubj)>=subj.length#lengtharr[i]
      next
    else
      toadd = subj[studpersubj]
      possans+= toadd if toadd>0
#      possans+=subj[studpersubj-1] if subj[studpersubj-1]>=0
    end
#    if studpersubj==1
#      p subj
#      p possans
#    end
  end

#  if studpersubj==1
#    nicep arr
#    p possans
#  end
  
#  $lookup[studpersubj] = possans
  return possans
end

=begin
while possans>=prevpossans
#  p possans
  prevpossans = possans
  possans = compute(newarr,studpersubj)
  if possans<=0
    break
  end
  studpersubj+=1
end
=end

#nicep newarr

left = 0
right = lengtharr.max

prevmid = -1

while left<right
  mid = (left+right)/2
  me = compute(newarr,mid,lengtharr)
  meplusone = compute(newarr,mid+1,lengtharr)

#  puts "#{left} #{right} #{mid} #{me} #{meplusone}"

  if meplusone>me
    left = mid
  else
    right = mid
  end
  if mid==prevmid
    break
  end
  prevmid = mid
end

puts [me,meplusone].max
