a = gets.chomp.split(" ").map(&:to_i)
b = gets.chomp.split(" ").map(&:to_i)
c = gets.chomp.split(" ").map(&:to_i)

xa = a[0]
ya = a[1]
xb = b[0]
yb = b[1]
xc = c[0]
yc = c[1]

ans = (xa-xb).abs + (ya-yb).abs + 1

rectop = [xa,xb].max
recbot = [xa,xb].min
recright = [ya,yb].max
recleft = [ya,yb].min

userecver = 0

if xc< recbot
  userecver = -1
  ans += recbot-xc
elsif xc > rectop
  userecver = 1
  ans += xc-rectop
end

userecside = 0
if yc< recleft
  userecside = -1
  ans += recleft-yc
elsif yc > recright
  userecside = 1
  ans += yc-recright
end

#ans += 1
puts ans

#puts userecver
#puts userecside

if userecver == -1
  #you definitely need the bottom
  (recleft..recright).each do |k|
    puts "#{recbot} #{k}"
  end

  if xa == recbot
    (recbot+1..xb).each do |k|
      puts "#{k} #{yb}"
    end
  else
    (recbot+1..xa).each do |k|
      puts "#{k} #{ya}"
    end
  end

  #DO THE C STUFF
  if userecside == -1
    (xc..recbot-1).each do |k|
      puts "#{k} #{yc}"
    end
    (yc+1..recleft-1).each do |k|
      puts "#{recbot} #{k}"
    end

  elsif userecside == 1
    (xc..recbot-1).each do |k|
      puts "#{k} #{yc}"
    end
    (recright+1..yc).each do |k|
      puts "#{recbot} #{k}"
    end

  else
    (xc..recbot-1).each do |k|
      puts "#{k} #{yc}"
    end
  end

elsif userecver == 1

  #you definitely need the top
  (recleft..recright).each do |k|
    puts "#{rectop} #{k}"
  end

  if xa == rectop
    (xb..rectop-1).each do |k|
      puts "#{k} #{yb}"
    end
  else
    (xa..rectop-1).each do |k|
      puts "#{k} #{ya}"
    end
  end

  #DO the C stuff
  if userecside == -1
    (rectop+1..xc).each do |k|
      puts "#{k} #{recleft}"
    end
    (yc..recleft-1).each do |k|
      puts "#{xc} #{k}"
    end

  elsif userecside == 1
    (rectop+1..xc).each do |k|
      puts "#{k} #{recright}"
    end
    (recright+1..yc).each do |k|
      puts "#{xc} #{k}"
    end

  else
    (rectop+1..xc).each do |k|
      puts "#{k} #{yc}"
    end
  end

else
  #You don't need the top or bottom, you may need the left or right

  if userecside == -1
    #You need the left
    (recbot..rectop).each do |k|
      puts "#{k} #{recleft}"
    end

    if ya == recleft
      (recleft+1..yb).each do |k|
        puts "#{xb} #{k}"
      end
    else
      (recleft+1..ya).each do |k|
        puts "#{xa} #{k}"
      end
    end

    (yc..recleft-1).each do |k|
      puts "#{xc} #{k}"
    end

  elsif userecside == 1
    #You need the right
    (recbot..rectop).each do |k|
      puts "#{k} #{recright}"
    end

    if ya == recright
      (yb..recright-1).each do |k|
        puts "#{xb} #{k}"
      end
    else
      (ya..recright-1).each do |k|
        puts "#{xa} #{k}"
      end
    end

    (recright+1..yc).each do |k|
      puts "#{xc} #{k}"
    end

  else
    #0,0 -> do a,c, c,b

    acxmin = [xa,xc].min
    acxmax = [xa,xc].max

    acymin = [ya,yc].min
    acymax = [ya,yc].max

    bcxmin = [xb,xc].min
    bcxmax = [xb,xc].max

    bcymin = [yb,yc].min
    bcymax = [yb,yc].max
    

    if xa<xc
      (xa..xc-1).each do |k|
        puts "#{k} #{ya}"
      end
    else
      (xc+1..xa).each do |k|
        puts "#{k} #{ya}"
      end
    end
    
    if ya<yc
      (ya..yc).each do |k|
        puts "#{xc} #{k}"
      end
    else
      (yc..ya).each do |k|
        puts "#{xc} #{k}"
      end
    end
    
    if xb<xc
      (xb..xc-1).each do |k|
        puts "#{k} #{yc}"
      end
    else
      (xc+1..xb).each do |k|
        puts "#{k} #{yc}"
      end
    end

    if yb<yc
      (yb..yc-1).each do |k|
        puts "#{xb} #{k}"
      end
    else
      (yc+1..yb).each do |k|
        puts "#{xb} #{k}"
      end
    end

  end
end
