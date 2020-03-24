if File.exists?("input")
  $stdin = File.open("input")
  $stdout = File.open("output","w")
end

nmk = gets.chomp.split(' ').map(&:to_i)
n = nmk[0]
m = nmk[1]
k = nmk[2]

arr = gets.chomp.split(" ").map(&:to_i)

max=0
maxtwo=0

(0..n-1).each do |i|
	if(arr[i]>max)
    	maxtwo = max
    	max=arr[i]
    elsif(arr[i]>maxtwo)
    	maxtwo = arr[i]
    end
end

ans=(m/(k+1))*(max*(k)+maxtwo)
leftover = m-(m/(k+1))*(k+1);
ans+=max*leftover

puts ans