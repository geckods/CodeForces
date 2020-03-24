if File.exists?("input")
  $stdin = File.open("input")
  $stdout = File.open("output","w")
end

whwh = gets.chomp.split(" ").map(&:to_i)
w1=whwh[0]
h1=whwh[1]
w2=whwh[2]
h2=whwh[3]

ans = h1+h2+w1+w2+4+h1+h2+(w1-w2).abs
puts ans