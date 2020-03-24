n = gets.to_i
arr = gets.chomp.split(" ").map(&:to_i)

posindex = []
negindex = []
zeroindex = []

zerocount = 0
negcount = 0
poscount = 0

lowestneg = -(10**9+1)
lowestnegindex = -1

arr.each_with_index do |x,i|
  if (x>0)
    posindex.push i+1
    poscount += 1
  elsif x==0
    zeroindex.push i+1
    zerocount += 1
  else

    if x > lowestneg
      lowestneg = x
      lowestnegindex = i+1
    end

    negindex.push i+1
    negcount += 1
  end
end

if negcount%2==0
  if zerocount==0
    #multiply everything
    (1..n-1).each do |z|
      puts "1 #{z} #{z+1}"
    end
  else
    #multiply zeroes
    
    lastzero = zeroindex[-1]

    zeroindex.each_with_index do |k,i|
      next if i==(zerocount-1)
      puts "1 #{k} #{zeroindex[i+1]}"
    end

    #delete last zero
    puts "2 #{lastzero}" unless (negcount == 0 and poscount == 0)

    lastneg = negindex[-1]

    #multiply everything else
    negindex.each_with_index do |k,i|
      next if i==(negcount-1)
      puts "1 #{k} #{negindex[i+1]}"
    end

    puts "1 #{lastneg} #{posindex[0]}" unless (posindex.empty? or negindex.empty?)

    posindex.each_with_index do |k,i|
      next if i==(poscount-1)
      puts "1 #{k} #{posindex[i+1]}"
    end
  end
else
  if zerocount==0
    #delete lowest negative
    puts "2 #{lowestnegindex}"
    #multiply everything else
    printarr = []

    if lowestnegindex == n
      (1..n-2).each do |z|
        puts "1 #{z} #{z+1}"
      end
    else
      (1..n-1).each {|x| printarr.push x unless x==lowestnegindex}
      printarr.push n
      printarr.each_with_index do |z,i|
        next if z==n
        puts "1 #{z} #{printarr[i+1]}"
      end
    end

  else
    #multiply zeroes together
    lastzero = zeroindex[-1]

    zeroindex.each_with_index do |k,i|
      next if i==(zerocount-1)
      puts "1 #{k} #{zeroindex[i+1]}"
    end

    #multiple last zero with lowest negative
    puts "1 #{lastzero} #{lowestnegindex}"

    #delete lowest negative index
    puts "2 #{lowestnegindex}" unless zerocount == n-1
    
    #multiply everything else
    negindex.delete_at(negindex.index(lowestnegindex))
   #p negindex
    negindex.each_with_index do |k,i|
      next if i==(negindex.length-1)
      puts "1 #{k} #{negindex[i+1]}"
    end

    puts "1 #{lastneg} #{posindex[0]}" unless (posindex.empty? or negindex.empty?)

    posindex.each_with_index do |k,i|
      next if i==(poscount-1)
      puts "1 #{k} #{posindex[i+1]}"
    end
  end
end



