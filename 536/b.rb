if File.exists?("input")
  $stdin = File.open("input")
  $stdout = File.open("output","w")
end

nm = gets.chomp.split(" ").map(&:to_i)
n = nm[0]
m = nm[1]
amount = gets.chomp.split(" ").map(&:to_i)
cost = gets.chomp.split(" ").map(&:to_i)
orders = []
m.times do
	orders.push gets.chomp.split(" ").map(&:to_i)
end

costin = []

(0..n-1).each do |i|
	costin.push [cost[i],i]
end

costin.sort_by!{|x| [x[0],x[1]]}

cheapestindex = 0

orders.each do |ord|
	type = ord[0]-1
	num = ord[1]

	totalcost = 0

	if cheapestindex==n
		puts totalcost
		next
	end

	left = amount[type]

	if(num<=left)
		amount[type]-=num
		totalcost+=num*cost[type]
		num=0
	else
		totalcost+=left*cost[type]		
		amount[type]=0
		num-=left
		while(num>0)
			nextdishind = costin[cheapestindex][1]
			left = amount[nextdishind]

			if(left<1)
				cheapestindex+=1
				if cheapestindex==n
					break
				end
				nextdishind = costin[cheapestindex][1]
				left = amount[nextdishind]
			end

			if(num<=left)
				amount[nextdishind]-=num
				totalcost+=num*cost[nextdishind]
				num=0
			else
				totalcost+=left*cost[nextdishind]
				amount[nextdishind]=0
				num-=left
			end
		end
	end

#	p amount
	
	if num>0
		puts 0
	else
		puts totalcost
	end
end
