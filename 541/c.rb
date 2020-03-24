if File.exists?("input")
  $stdin = File.open("input")
  $stdout = File.open("output","w")
end

n = gets.to_i
arr = []
arr= gets.chomp.split(" ").map(&:to_i)

def getdisc(arr)
	max = 0
	arr[1..-1].each_with_index do |x,i|
		asd = (x-arr[i-1]).abs
		max = asd if asd>max
	end
	asd = (arr[-1]-arr[0]).abs
	max=asd if asd>max
	return max
end

def newgetdisc(arr)
	max = 0
	arr[1..-1].each_with_index do |x,i|
		asd = (x-arr[i-1]).abs
		max+= asd
	end
	asd = (arr[-1]-arr[0]).abs
	max+=asd# if asd>max
	return max
end

def swap(arr,a,b)
	temp  = arr[a]
	arr[a]=arr[b]
	arr[b]=temp
	return arr
end

#newarr = []
#disc = 

#p arr
=begin
arr.each do |x|
	if newarr.length==0
		newarr.push x
	else
		scorearr = []
		(0..newarr.length).each do |insloc|
			newnewarr = newarr.dup
			newnewarr.insert(insloc,x)
			scorearr.push newgetdisc(newnewarr)
		end
		theloc = scorearr.index(scorearr.min)
		newarr.insert(theloc,x)
	end
	p newarr
end
=end
=begin
newarr = arr.dup

while true
	currscore = getdisc(newarr)
	tobreak = false
	newarr.each_with_index do |x,i|
		newarr[i+1..-1].each_with_index do |y,j|
			newnewarr = newarr.dup
			newnewarr = swap(newnewarr,i,j)
			if(getdisc(newnewarr)<currscore)
				newarr=newnewarr.dup
				tobreak = true
				break
			end
		end
		break if tobreak
	end

	break if not tobreak
end
p newarr
=end

arr.sort!
newarr = []
arr.each_with_index do |x,i|
	newarr.push x if i%2==0
end

arr.reverse!

if arr.length%2==0
	arr.each_with_index do |x,i|
		newarr.push x if i%2==0
	end
else
	arr.each_with_index do |x,i|
		newarr.push x if i%2==1
	end
end

newarr.each do |x|
	print x
	print " "
end
puts