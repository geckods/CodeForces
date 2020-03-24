nk = gets.chomp.split(" ").map(&:to_i)
n = nk[0]
k = nk[1]
h = Hash.new(0)
food = gets.chomp.split(" ").map(&:to_i)

food.each do |pa|
  h[pa]+=1
end

if k<n
  puts 0
  exit
end

day = 1

while true
  peoplecount = 0
  h.each do |foodtype,foodno|
    peoplecount += foodno/day
    if peoplecount >= n
      day+=1
      break
    end
  end

  if peoplecount < n
    puts day-1
    exit
  end
end
    
