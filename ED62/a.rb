require 'set'
#if File.exists?("input")
#  $stdin = File.open("input")
#  $stdout = File.open("output","w")
#end
n = gets.to_i
arr = gets.chomp.split(" ").map(&:to_i)

i=0
ans=0
mySet = Set.new

while(i<n)
	ans+=1;
    loop do
		mySet.add(arr[i])
    	if(mySet.include?(i+1))
    		mySet.delete(i+1)
    	end
    	i+=1
    	break if mySet.empty?
    end
end

puts ans