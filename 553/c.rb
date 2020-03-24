if File.exists?("input")
  $stdin = File.open("input")
  $stdout = File.open("output","w")
end


def foo(x)
	return 0 if(x==0)
	xlog = (Math.log(x)/Math.log(2)).to_i
	ans=0
	if(xlog%2==1)
		#our last number is odd
		asd = (xlog-1)/2
		numberofodds = (((4**(asd+1))-1)/3)
		numberofevens = x-numberofodds
		ans += numberofevens**2 + numberofevens
		ans += numberofodds**2
		return ans
	else
		#our last number is even
		asd = (xlog-2)/2
		numberofevens = 2*(((4**(asd+1))-1)/3)
		numberofodds = x-numberofevens
		ans += numberofevens**2 + numberofevens
		ans += numberofodds**2
		return ans
	end
end


lr = gets.chomp.split(" ").map(&:to_i)

l = lr[0]
r = lr[1]
puts (foo(r)-foo(l-1))%1000000007
