x = gets.to_i

if x==1 or x==2
  puts "No"
  exit
else
  puts "Yes"
  
  if x%2==0
    print "#{x/2} "
    a = 1
    while (a<=x)
      print "#{a} "
      a += 2
    end

    puts
    print "#{x/2} "
    a = 2
    while (a<=x)
      print "#{a} "
      a += 2
    end

  else

    print "#{x/2 +1} "
    a = 1
    while (a<=x)
      print "#{a} "
      a += 2
    end

    puts
    print "#{x/2 } "
    a = 2
    while (a<=x)
      print "#{a} "
      a += 2
    end
  end
  puts
end
