t = gets.to_i

t.times do
  n = gets.to_i
  arr = gets.chomp.split(" ").map(&:to_i)

  hash = Hash.new(0)
  newarr = []
  doneflag = 0

  arr.each do |x|
    hash[x]+=1
    if hash[x] == 2
      newarr.push x
      newarr.sort!.reverse!
=begin
      i = newarr.length
      newarr.each_with_index do |z,ind|
        if z<x
          i = ind
          break
        end
      end
      newarr.insert(i,x)
=end
      ##hash[x] = 0
    end
    if hash[x] == 4
      puts "#{x} #{x} #{x} #{x}"
      doneflag = 1
      break
    end
  end

  #p newarr

  if doneflag==1
    next
  end

  min = 1.0/0.0
  minind = 0
  len = newarr.length
  (0..len-2).each do |z|
    ratio = (newarr[z]/newarr[z+1]-1)
    if ratio<min
      min = ratio
      minind = z
    end
  end

  ans1 = newarr[minind]
  ans2 = newarr[minind+1]

  puts "#{ans1} #{ans1} #{ans2} #{ans2}"
    
end
