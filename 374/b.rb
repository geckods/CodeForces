if File.exists?("input")
  $stdin = File.open("input")
  $stdout = File.open("output","w")
end

nk = gets.chomp.split(" ").map(&:to_i)
n = nk[0]
k = nk[1]
arr = []

n.times do
	arr.push gets.chomp
end

correct = gets.chomp
correctlen = correct.length

arr.sort_by!{|x| x.length}

count = 0
ans=0
minians = 0
maxians = 0

arr.each_with_index do |x,i|
	ans+=1
	count+=1

#	p "#{i} #{ans} #{correctlen} #{x.length}"

	if(x.length == correctlen && minians == 0)
		minians = ans
	end

	if(x.length == correctlen && (i==n-1 || arr[i+1].length > correctlen))
		maxians=ans
	end

	ans+=5 if(count%k==0)
end

print "#{minians} #{maxians}"
puts
