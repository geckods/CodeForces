n = gets.to_i
arr = gets.chomp.split(" ").map(&:to_i)

k = 0
arr.each_with_index do |z,i|
  if z>k
    puts i+1
    exit
  elsif z==k
    k+=1
  end
end

puts -1
