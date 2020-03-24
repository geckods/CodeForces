require 'set'

if File.exists?("input")
  $stdin = File.open("input")
  $stdout = File.open("output","w")
end


n = gets.to_i
nodes = gets.chomp.split(" ").map(&:to_i)
edgehash = Hash.new([])

def gcd(a, b)
  b == 0 ? a : gcd(b, a.modulo(b))
end

(n-1).times do
  edge = gets.chomp.split(" ").map(&:to_i)
  a = edge[0]-1
  b = edge[1]-1
  next unless gcd(nodes[a],nodes[b]) > 1
  edgehash[a] += [b]
  edgehash[b] += [a]
end
#puts "HI"

def gcd_dfs(node,nodes,edgehash,distance,thegcd,seen)
  seen.add(node)
  distances = []
  edgehash[node].each do |nextnode|
  	next if seen.include?(nextnode)
    newgcd = gcd(thegcd,nodes[nextnode])
    if newgcd>1
      distances.push gcd_dfs(nextnode,nodes,edgehash,distance+1,newgcd,seen)
    end
  end

  if distances.empty?
    return distance
  else
    return distances.max
  end
end

#p edgehash

max = 0
(0..n-1).each do |nodeno|
  next if nodes[nodeno]==1
  asdf = gcd_dfs(nodeno,nodes,edgehash,1,nodes[nodeno],Set.new)
#  puts "#{nodeno} #{asdf}"
  max = asdf if asdf > max
end

puts max