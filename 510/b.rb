n = gets.to_i
array = Array.new

n.times do
  miniarr = gets.chomp.split(" ")
  miniarr[0] = miniarr[0].to_i
  miniarr[1] = miniarr[1].each_char.to_a.sort.join("")
  array.push miniarr
end
#p array

combcost = Hash.new(1000000)

array.each do |juice|
  cost = juice[0]
  type = juice[1]

  if cost < combcost[type]
    combcost[type] = cost
  end
end

ans = [combcost["A"]+combcost["B"]+combcost["C"],combcost["A"]+combcost["BC"],combcost["AB"]+combcost["C"],combcost["B"]+combcost["AC"],combcost["AB"]+combcost["BC"],combcost["AC"]+combcost["BC"],combcost["AB"]+combcost["AC"],combcost["ABC"]].min

if ans>300000
  ans = -1
end
puts ans
