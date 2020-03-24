if File.exists?("input")
  $stdin = File.open("input")
  $stdout = File.open("output","w")
end

#use moving window to get the sum
nk = gets.chomp.split(" ").map(&:to_i)
n = nk[0]
k = nk[1]
a = gets.chomp.split(" ").map(&:to_i)
s = gets.chomp

arr = [0]
breakpoints = 2
(1..n-1).each do |i|
	if s[i]!=s[i-1]
		breakpoints+=1
		arr.push i
	end
end
arr.push n

totsum = 0
#bigarr = []
=begin

(0..breakpoints-2).each do |st|
	newarr = []
	newlen = 1
	min = 1.0/0.0
	sum = 0
	max = 0
	(arr[st]..arr[st+1]-1).each do |range|
		this = a[range]
#		p newlen
		if(newlen<=k)
			newarr.push this
			sum+=this
			min = this if this<min
			newlen+=1
		else
			if (this>min)
				sum-=min
				sum+=this
				newarr.push this
				newarr.delete_at(newarr.index(min))
				min = newarr.min
			end
		end
		max = sum if sum>max
	end
	totsum += sum
end
=end
#p arr
(0..breakpoints-2).each do |st|
	newarr = a[arr[st]..arr[st+1]-1].sort
#	p newarr
	initi = newarr.length-1
	i = initi
	min = arr[st]
	sum = 0
#	p initi
	while true
		break if (initi-i+1)>k
		break if i<0
#		p i
		sum+=newarr[i]
		i -= 1
#		p sum
	end
#	p sum
	totsum += sum
end


#p arr
puts totsum