ahyp = "X"*30
bhyp = "X"*30
checkedi = 0

puts "? " + "0" + " " + "0"
STDOUT.flush
ans = gets.chomp.to_i

if ans==1
  aisgreater = true
  theyareequal = false
elsif ans==-1
  aisgreater = false
  theyareequal = false
else
  aisgreater = false
  theyareequal = true
end 

preva = ""
prevb = ""

61.times do

#  p ahyp
#  p bhyp

  if aisgreater and not theyareequal
    puts "? " + (preva+"1"+"0"*(29-checkedi)).to_i(2).to_s + " " + (prevb+"0"+"0"*(29-checkedi)).to_i(2).to_s
    STDOUT.flush
    res = gets.to_i

    if res==1
    puts "? " + (preva+"0"+"0"*(29-checkedi)).to_i(2).to_s + " " + (prevb+"1"+"0"*(29-checkedi)).to_i(2).to_s
      STDOUT.flush
      newres = gets.to_i

      if newres ==1
        ahyp[checkedi] = "1"
        bhyp[checkedi] = "0"
        aisgreater = true
        #ALAT > BLAT
      elsif newres==-1
        ahyp[checkedi] = "0"
        bhyp[checkedi] = "0"
        aisgreater = true
        #ALAT > BLAT
      end
    elsif res==-1
      puts "? " + (preva+"0"+"0"*(29-checkedi)).to_i(2).to_s + " " + (prevb+"1"+"0"*(29-checkedi)).to_i(2).to_s
      STDOUT.flush
      newres = gets.to_i

      if newres ==1
        ahyp[checkedi] = "1"
        bhyp[checkedi] = "1"
        aisgreater = true
        #ALAT>BLAT
      elsif newres==-1
        ahyp[checkedi] = "1"
        bhyp[checkedi] = "0"
        aisgreater = false
        #ALAT<BLAT
      end
    else
      ahyp[checkedi] = "1"
      bhyp[checkedi] = "0"
      theyareequal = true
      #DEAL WITH EQUALITY HERE
    end
    #UPDATE PREVSTRINGS, INCREASE ITERVAR

  elsif (not aisgreater) and (not theyareequal)
    puts "? " + (preva+"0"+"0"*(29-checkedi)).to_i(2).to_s + " " + (prevb+"1"+"0"*(29-checkedi)).to_i(2).to_s
    STDOUT.flush
    res = gets.to_i

    if res==1
      puts "? " + (preva+"1"+"0"*(29-checkedi)).to_i(2).to_s + " " + (prevb+"0"+"0"*(29-checkedi)).to_i(2).to_s
      STDOUT.flush
      newres = gets.to_i

      if newres ==1
        ahyp[checkedi] = "0"
        bhyp[checkedi] = "1"
        aisgreater = true
        #ALAT>BLAT
      elsif newres==-1
        ahyp[checkedi] = "1"
        bhyp[checkedi] = "1"
        aisgreater = false
        #ALAT<BLAT
      end
    elsif res==-1
      puts "? " + (preva+"1"+"0"*(29-checkedi)).to_i(2).to_s + " " + (prevb+"0"+"0"*(29-checkedi)).to_i(2).to_s
      STDOUT.flush
      newres = gets.to_i
      if newres ==1
        ahyp[checkedi] = "0"
        bhyp[checkedi] = "0"
        aisgreater = false
        #ALAT<BLAT
      elsif newres==-1
        ahyp[checkedi] = "0"
        bhyp[checkedi] = "1"
        aisgreater = false
        #ALAT<BLAT
      end
    else
      ahyp[checkedi] = "0"
      bhyp[checkedi] = "1"
      theyareequal = true
      #DEAL WITH EQUALITY HERE
    end

  elsif theyareequal
    puts "? " + (preva+"1"+"0"*(29-checkedi)).to_i(2).to_s + " " + (prevb+"0"+"0"*(29-checkedi)).to_i(2).to_s
    STDOUT.flush
    res = gets.to_i

    if res==1
      ahyp[checkedi] = "0"
      bhyp[checkedi] = "0"
    else
      ahyp[checkedi] = "1"
      bhyp[checkedi] = "1"
    end
    theyareequal = false
    #DEAL WITH EQUALITY
  end

  preva = ahyp[0..checkedi]
  prevb = bhyp[0..checkedi]
  checkedi = checkedi+1

  if (not ahyp.include?("X"))
    puts "! " + ahyp.to_i(2).to_s + " " + bhyp.to_i(2).to_s
    exit
  end

  #UPDATE PREVSTRINGS, INCREASE ITERVAR
end
