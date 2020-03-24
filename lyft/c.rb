nm = gets.chomp.split(" ").map(&:to_i)
n = nm[0]
m = nm[1]

vertiarr = []
horiarr = []

n.times {vertiarr.push gets.to_i}
m.times {horiarr.push gets.chomp.split(" ").map(&:to_i)}

newhoriarr = []

horiarr.each do |z|
  newhoriarr.push z if z[0]==1
end

#vertiarr.push 0
#vertiarr.push 10**9
vertiarr = vertiarr.sort.reverse

horihash = Hash.new(0)
countver = 0

newhoriarr = newhoriarr.sort_by{|x| x[1]}.reverse

#p vertiarr
#p newhoriarr

nextone = 10**9
newhoriarr.each_with_index do |hori,i|
  break if countver >= n
  endpoint = hori[1]

  while(endpoint<nextone)
#    puts "#{i} #{endpoint} #{nextone}"
    nextone = vertiarr[countver]
    horihash[nextone] = i
    countver+=1
    break if countver==n
  end

  horihash[vertiarr[countver]] = i+1

  if countver==n
    horihash[0] = i
    if endpoint>=vertiarr[n-1]
      horihash[0]+=1
    end
  end

end

vertiarr.each_with_index do |x,i|
  next if i==0
  if horihash[x]==0
    horihash[x] = horihash[vertiarr[i-1]]
  end
end

if n==0
  horihash[0] = newhoriarr.count{|x| x[1]>=10**9}
else
  horihash[0] = newhoriarr.count{|x| x[1]>=vertiarr[n-1]}
end

#p horihash

min = 1.0/0.0
vertiarr.push 0
vertiarr.reverse.each_with_index do |vert,i|
  ans = i+horihash[vert]
#  puts "#{i} #{ans}"
  if ans<min
    min = ans
  end
end

puts min

