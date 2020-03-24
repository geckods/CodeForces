def optimize(x,y)
	arr = []
	x.times {arr.push 1}
	y.times {arr.push 0}
	ans = 0
	while(arr.size>0)
		asd = arr.shift
		ans+=asd
		arr = arr.map{|x| x+=asd}
	end
	return ans
end

(0..13).each do |x|
	p "#{x} #{13-x} #{optimize(x,13-x)}"
end
