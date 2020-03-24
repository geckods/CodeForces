if File.exists?("input")
  $stdin = File.open("input")
  $stdout = File.open("output","w")
end

n = gets.to_i
arr = []
n.times do
	arr.push gets.chomp.split(" ").map(&:to_i)
end

prevx = 0
prevy = 0

def inrange(a,b,x)
	return true if x>=a and x<=b
end



ans = 0

maxtie = -1

arr.each do |z|
	x = z[0]
	y = z[1]


#	if(prevx==x && prevy==y)
#		next
#	end


	if(y<prevx || x<prevy)
		prevx = x
		prevy = y
		prevx+=1 if prevx==maxtie
		prevy+=1 if prevy==maxtie
		next
	elsif(x==y && prevx==prevy)
		ans+=x-prevx+1
		prevx=x+1
		prevy=y+1
		maxtie=x
		next
	else
		if(inrange(prevx,x,prevy))
			if(inrange(prevx,x,y))
				ans+=y-prevy+1
				maxtie = y
			else
				ans+=x-prevy+1
				maxtie = x
			end
		elsif(inrange(prevx,x,y))
			ans+=y-prevx+1
			maxtie = y
		else#(inrange(prevy,y,prevx)&&inrange(prevy,y,x))
			ans+=x-prevx+1
			maxtie = x
		end

	end
=begin
	p x
	p y
	p prevx
	p prevy
#	p toincx
#	p toincy
	p maxtie
	p ans
	puts
=end
	prevx=x
	prevy=y

	prevx+=1 if prevx==maxtie
	prevy+=1 if prevy==maxtie

end

#if arr[n-1][0]==0 and arr[n-1][1]==0
#	ans+=1
#end
puts ans