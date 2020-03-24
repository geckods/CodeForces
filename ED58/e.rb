if File.exists?("input")
  $stdin = File.open("input")
  $stdout = File.open("output","w")
end

n = gets.to_i

maxone = 0
maxtwo = 0
n.times do
  q = gets.chomp.split(" ")
  if q[0]=="+"
    size = q[1..2].map(&:to_i).sort
    maxone = size[0] if size[0]>maxone
    maxtwo = size[1] if size[1]>maxtwo
  else
    size = q[1..2].map(&:to_i).sort
    if size[0]>=maxone and size[1]>=maxtwo
      puts "YES"
    else
      puts "NO"
    end
  end
end