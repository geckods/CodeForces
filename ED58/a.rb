if File.exists?("input")
  $stdin = File.open("input")
  $stdout = File.open("output","w")
end


q = gets.to_i
q.times do
  lrd = gets.chomp.split(" ").map(&:to_i)
  l = lrd[0]
  r = lrd[1]
  d = lrd[2]
  if d<l
    puts d
  else
    a = (r/d)*d
    while a<=r
      a += d
    end
    puts a
  end
end