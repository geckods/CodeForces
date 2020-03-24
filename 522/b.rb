text = gets.chomp
len = text.length

reqa = 0
reqb = 0

done = false

(1..5).each do |a|
  (1..20).each do |b|
    tot = a*b
    if tot<len
      next
    else
      reqa = a
      reqb = b
      done = true
      break
    end
  end
  break if done 
end

delta = reqa*reqb - len

astperrow = delta/reqa
rowast = []
reqa.times {rowast.push astperrow}

(0..reqa-1).each do |i|
  if rowast.inject(:+)<delta
    rowast[i] += 1
  end
end

currchar = 0
printed = 0


puts "#{reqa} #{reqb}"
(0..reqa-1).each do |row|
  while printed<reqb
    if(printed<reqb-rowast[row])
      print text[currchar]
      currchar+=1
      printed += 1
    else
      print '*'
      printed += 1
    end
  end
  puts
  printed = 0
end
