nk = gets.chomp.split(" ").map(&:to_i)
arr = gets.chomp.split(" ").map(&:to_i)
n = nk[0]
k = nk[1]
tosubtr = 0

arr.sort!
#p arr

i = 0
k.times do

  if i >= n
    puts 0
  else
    x = arr[i]

    while ((x-tosubtr)==0 and i<n-1)
      i += 1
      x = arr[i]
    end

    if i==n
      puts 0
      continue
    end

#    puts "#{x} #{tosubtr}"

    if x-tosubtr<=0
      puts 0
    else
      puts x-tosubtr
      tosubtr = x
    end

  end
  i += 1
end
