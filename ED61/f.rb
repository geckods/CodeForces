if File.exists?("input")
  $stdin = File.open("input")
  $stdout = File.open("output","w")
end


n = gets.to_i
str = gets.chomp

arr = []
n.times {arr.push [0]*n}

(0..n-1).each do |sublen|
	(0..n-1-sublen).each do |start|
		if sublen==0 || str[start..start+sublen].each_char.to_a.uniq.length==1
			arr[start][start+sublen]=1
		else
			min = 1.0/0.0
			(0..sublen-1).each do |len|
				ans = arr[start][start+len]+arr[start+len+1][start+sublen]
				min=ans if ans<min
			end
			arr[start][start+sublen]=min
		end
	end
end

p arr