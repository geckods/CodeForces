(1..(n=gets.to_i)).to_a.each_slice((n**0.5).to_i).to_a.reverse.flatten.each {|x| print "#{x} "}
