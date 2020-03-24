if File.exists?("input")
  $stdin = File.open("input")
  $stdout = File.open("output","w")
end

n = gets.to_i
n.times do
  kx = gets.chomp.split(" ").map(&:to_i)
  k = kx[0]
  x = kx[1]

  puts 9*(k-1) + x
end