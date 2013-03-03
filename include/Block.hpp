#ifndef HDX_BOCK_H_INCLUDE
#define HDX_BOCK_H_INCLUDE


class Block
{
  public:

    Block(Block &block);

    virtual ~Block();

    void name(std::string name);
    std::string name() const;

    void definition(std::string definition);
    std::string definition() const;

    // Tag getTag(std::string tag_id) const;

    /// @todo Iterate by name
    //iterator<Tag> tags() const;

    //Tag createTag(std::string name, std::string type) const;

    //void deleteTag(std::string tag_id) const;

    //void deleteTag(Tag &tag) const;

    //iterator<Source> sources() const;

  private:
};

#endif // HDX_BOCK_H_INCLUDE
