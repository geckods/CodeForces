n = gets.to_i
arr = gets.chomp.split(" ").map(&:to_i)

max = 0
maxtwo = 0
min = 1.0/0.0
mintwo = 1.0/0.0

arr.each do |x|
  if x > max
    maxtwo = max
    max = x
  elsif x > maxtwo
    maxtwo = x
  end

  if x < min
    mintwo = min
    min = x
  elsif x <mintwo
    mintwo = x
  end
end

puts [maxtwo-min,max-mintwo].min
