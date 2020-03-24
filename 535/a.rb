if File.exists?("input")
  $stdin = File.open("input")
  $stdout = File.open("output","w")
end

q = gets.to_i
q.times do
	lrlr = gets.chomp.split(" ").map(&:to_i)
	l1 = lrlr[0]
	r1 = lrlr[1]
	l2 = lrlr[2]
	r2 = lrlr[3]

	if (l1 == l2) and (l1==r2)
		puts "#{r1} #{l1}"
	else
		print "#{l1} "
		if(l1==l2)
			print r2
		else
			print l2
		end
		puts
	end
end