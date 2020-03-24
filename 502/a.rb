n = gets.to_i
arr = []
n.times do |i|
  arr.push [i+1]+gets.chomp.split(" ").map(&:to_i)
end

arr.sort_by!{|x| [-x[1..-1].inject(:+),x[0]]}


arr.each_with_index do |x,i|
  if x[0]==1
    puts i+1
    exit
  end
end

