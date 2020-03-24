if File.exists?("input")
  $stdin = File.open("input")
  $stdout = File.open("output","w")
end 

def inRange(x,l,r)
	if(l-1<=x and x<=r-1)
        return true
	else  
        return false
    end
end

nm = gets.chomp.split(" ").map(&:to_i)
n = nm[0]
m = nm[1]
arr = gets.chomp.split(" ").map(&:to_i)
range = []
m.times do
    range.push gets.chomp.split(" ").map(&:to_i)
end

inRangeArr = Hash.new([])

(0..n-1).each do |i|
    (0..m-1).each do |j|
    	if inRange(i,range[j][0],range[j][1])
            inRangeArr[i] += [j]
    	end
    end
end

best = 0
besti = -1

(0..n-1).each do |i|
    newarr = arr.dup
    inRangeArr[i].each do |a|
        l = range[a][0]
        r = range[a][1]
        (l..r).each do |k|
            newarr[k-1]-=1
        end
    end
    currbest = newarr.max-newarr.min
    if currbest > best
        best = currbest 
        besti = i
    end
   # p newarr
end

#p arr
#p inRangeArr
#p inRangeCount
#p besti

puts best
puts inRangeArr[besti].length
inRangeArr[besti].each_with_index do |r,ix|
#    if r==1
        print r+1
        print " "
#    end
end
puts