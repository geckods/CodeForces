#if File.exists?("input")
#  $stdin = File.open("input")
#  $stdout = File.open("output","w")
#end
require 'set'

$myset = Set.new

nmp = gets.chomp.split(" ").map(&:to_i)
$n = nmp[0]
$m = nmp[1]
p = nmp[2]

speeds = gets.chomp.split(" ").map(&:to_i)

grid = []
$n.times do
	grid.push gets.chomp.split("")
end

def step(grid,playerno,x,y,steps,arr)
	if steps==0
		return []
	end

	if(x!=0) and grid[x-1][y]=="." and not $myset.include?([x-1,y])
		grid[x-1][y]=playerno.to_s
		$myset.add([x-1,y])
		arr.push([x-1,y])
		arr += step(grid,playerno,x-1,y,steps-1,arr)
	end

	if(y!=0) and grid[x][y-1]=="." and not $myset.include?([x,y-1])
		grid[x][y-1]=playerno.to_s
		$myset.add([x,y-1])
		arr.push([x,y-1])
		arr += step(grid,playerno,x,y-1,steps-1,arr)
	end

	if(x<$n-1) and grid[x+1][y]=="." and not $myset.include?([x+1,y])
		grid[x+1][y]=playerno.to_s
				$myset.add([x+1,y])
		arr.push([x+1,y])
		arr += step(grid,playerno,x+1,y,steps-1,arr)
	end

	if(y<$m-1) and grid[x][y+1]=="." and not $myset.include?([x,y+1])
		grid[x][y+1]=playerno.to_s
				$myset.add([x,y+1])
		arr.push([x,y+1])
		arr += step(grid,playerno,x,y+1,steps-1,arr)
	end

	return arr
end

def onemove(grid,playerno,playerspeed,locations)
	newlocations = []
	locations.each do |loc|
		$myset.add(loc)
		x = loc[0]
		y = loc[1]
		newlocations += step(grid,playerno,x,y,playerspeed,[])
	end
	return newlocations
end

loc2d = []
p.times do
	loc2d.push []
end

(0..$n-1).each do |x|
	(0..$m-1).each do |y|
		if grid[x][y].to_i.to_s == grid[x][y]
			$myset.add([x,y])
			loc2d[grid[x][y].to_i-1].push [x,y]
		end
		if grid[x][y]=="#"
			$myset.add([x,y])
		end
	end
end

playerno = 1
while true
#	p playerno
	newlocations = onemove(grid,playerno,speeds[playerno-1],loc2d[playerno-1])
	loc2d[playerno-1]=newlocations
	playerno +=1
	playerno = 1 if playerno == p+1
	break if loc2d.flatten.length==0
end

(1..p).each do |x|
	print grid.flatten.count(x.to_s)
	print " "
end
puts

