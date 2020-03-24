if File.exists?("input")
  $stdin = File.open("input")
  $stdout = File.open("output","w")
end

t = gets.to_i
curr = 1

arr = []
t.times do
	str = gets.chomp
	if(str[0]=='f')
		arr.push str.split(" ")[-1].to_i
	elsif(str[0]=='a')
		arr.push 0
	else
		arr.push -1
	end
end

max = 2**32-1

list = []
workslist = []
ans=0
works = true

arr.each do |x|

#	p list
#	p workslist

	if(x==0)
		if(!works)
			puts "OVERFLOW!!!"
			exit
		end
		ans+=curr
	elsif(x>0)
		list.push x
		newmax = curr*x
		if(works && newmax < max)
			curr = newmax
			workslist.push works
		else
			works = false
			workslist.push works
		end
	else
		workslist.pop
		a = list.pop
		if(works)
			curr/=a
		end
		if(workslist.size>0)
			works = workslist[-1]
		else
			works = true
		end
	end

	if(ans>max)
		puts "OVERFLOW!!!"
		exit
	end
end

puts ans